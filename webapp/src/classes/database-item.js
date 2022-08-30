import { useWasmModuleStore } from "../stores/wasm-module";

class CDatabaseItem {
    constructor(itemType, itemName) {
        this.itemType = itemType;
        this.itemName = itemName;
        this.id = this.itemType + "-" + this.itemName;

        // general
        this.firstLoad = true;

        // columns
        this.columns = [];

        // rows
        this.rows = [];

        // pagination
        this.pagination = {
            sortBy: "",
            descending: false,
            page: 1,
            rowsPerPage: 50,
            rowsNumber: 0,
        };

        // loading
        this.loading = false;
    }

    load(props) {
        // module
        const wm = useWasmModuleStore();

        // general
        let { page, rowsPerPage, sortBy, descending } = props.pagination;

        this.loading = true;

        // check sort
        if (sortBy == null) {
            sortBy = "";
        }

        // load columns
        let columns = wm.module.Repository.shared().getColumns(this.itemName);
        let columnsData = [];

        for (let x = 0; x < columns.length; x++) {
            let column = columns[x];

            columnsData.push({
                name: column.name,
                required: true,
                label: column.name,
                align: "left",
                field: column.name,
                format: (val) => {
                    return val;
                },
                sortable: true,
                db: column,
            });
        }

        this.columns.splice(0, this.columns.length, ...columnsData);

        // sort by first column when load first time
        if (this.firstLoad) {
            if (columns.length > 0) {
                sortBy = columns[0].name;
            }
        }

        // load rows
        let rows = wm.module.Repository.shared().getRows(
            this.itemName,
            sortBy,
            descending,
            page - 1,
            rowsPerPage
        );

        let rowsData = [];

        for (let x = 0; x < rows.list.length; x++) {
            let rowData = {};

            for (let c = 0; c < columns.length; c++) {
                rowData[columns[c].name] = rows.list[x].values[c];
            }

            rowsData.push(rowData);
        }

        this.rows.splice(0, this.rows.length, ...rowsData);

        // pagination
        this.pagination.page = page;
        this.pagination.rowsPerPage = rowsPerPage;
        this.pagination.sortBy = sortBy;
        this.pagination.descending = descending;
        this.pagination.rowsNumber = rows.amount;

        // finish
        if (this.firstLoad) {
            this.firstLoad = false;
        }

        this.loading = false;
    }
}

export default CDatabaseItem;
