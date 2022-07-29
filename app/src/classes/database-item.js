import { ref } from "vue";

class CDatabaseItem {
    constructor(itemType, itemName) {
        this.itemType = itemType;
        this.itemName = itemName;

        // columns
        this.columns = [];

        // rows
        this.rows = [];

        // pagination
        this.pagination = ref({
            rowsPerPage: 0,
        });
    }

    load() {
        const WM = window.WM;

        // load columns
        let columns = WM.Repository.shared().getColumns(this.itemName);
        let columnsData = [];

        for (let x = 0; x < columns.length; x++) {
            let column = columns[x];

            columnsData.push({
                name: column.name,
                required: true,
                label: column.name,
                align: "left",
                field: column.name,
                format: (val) => `${val}`,
                sortable: false,
            });
        }

        this.columns = columnsData;

        // load rows
        let rows = WM.Repository.shared().getRows(this.itemName);
        let rowsData = [];

        for (let x = 0; x < rows.length; x++) {
            let row = rows[x];
            let rowData = {};

            for (let c = 0; c < columns.length; c++) {
                rowData[columns[c].name] = row.values[c];
            }

            rowsData.push(rowData);
        }

        this.rows = rowsData;
    }
}

export default CDatabaseItem;
