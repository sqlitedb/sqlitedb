<script setup>
import { useQuasar } from "quasar";
import { computed, onMounted } from "vue";
import CDatabaseItem from "../classes/database-item";
import { useRepositoryStore } from "../stores/repository";

const repository = useRepositoryStore();
const q = useQuasar();

const props = defineProps({
    databaseItem: CDatabaseItem,
});

const emit = defineEmits(["onRequest"]);

const pagination = computed({
    get: () => props.databaseItem.pagination,
    set: (val) => {
        onRequest({
            pagination: val,
        });
    },
});

function onRequest(data) {
    emit("onRequest", data);
}

function onClose() {
    repository.removeDatabaseItem(
        props.databaseItem.itemType,
        props.databaseItem.itemName
    );
}

function getTableColumnSlotName(column) {
    return "body-cell-" + column.name;
}

function isTableColumnGroupTypeText(column) {
    const type = column.groupType.toLowerCase();

    if (type == "text") {
        return true;
    }

    return false;
}

function isTableColumnGroupTypeBlob(column) {
    const type = column.groupType.toLowerCase();

    if (type == "blob") {
        return true;
    }

    return false;
}

function isTableColumnGroupTypeNumeric(column) {
    const type = column.groupType.toLowerCase();

    if (type == "numeric") {
        return true;
    }

    return false;
}

function isTableColumnGroupTypeInteger(column) {
    const type = column.groupType.toLowerCase();

    if (type == "integer") {
        return true;
    }

    return false;
}

function isTableColumnGroupTypeReal(column) {
    const type = column.groupType.toLowerCase();

    if (type == "real") {
        return true;
    }

    return false;
}

function openDialogForTextData(column, data) {
    q.dialog({
        title: "Field: " + column.name,
        message: data,
        class: "scroll",
        fullWidth: true,
        fullHeight: true,
    });
}

function openDialogForBlobData(column, data) {
    q.dialog({
        title: "Field: " + column.name,
        message: data,
        class: "scroll",
        fullWidth: true,
        fullHeight: true,
    });
}

onMounted(() => {
    onRequest({
        pagination: props.databaseItem.pagination,
    });
});
</script>

<template>
    <div>
        <div class="no-shadow">
            <q-item>
                <q-item-section side>
                    <q-avatar
                        v-if="databaseItem.itemType == 'table'"
                        icon="table_rows"
                        color="indigo"
                        text-color="white"
                        size="24px"
                    />
                    <q-avatar
                        v-else-if="databaseItem.itemType == 'view'"
                        icon="flash_on"
                        color="indigo"
                        text-color="white"
                        size="24px"
                    />
                </q-item-section>
                <q-item-section>
                    <q-item-label v-if="databaseItem.itemType == 'table'"
                        >Table: {{ databaseItem.itemName }}
                    </q-item-label>
                    <q-item-label v-else-if="databaseItem.itemType == 'view'"
                        >View: {{ databaseItem.itemName }}
                    </q-item-label>
                </q-item-section>
                <q-item-section>
                    <q-btn
                        flat
                        color="primary"
                        label="Close"
                        @click="onClose"
                    />
                </q-item-section>
            </q-item>

            <q-table
                class="custom-table no-border-radius no-shadow sticky-virtscroll-table"
                :rows="databaseItem.rows"
                :columns="databaseItem.columns"
                row-key="index"
                virtual-scroll
                separator="cell"
                v-model:pagination="pagination"
                :virtual-scroll-sticky-size-start="48"
                @request="onRequest"
            >
                <template
                    v-for="columnItem in databaseItem.columns"
                    :key="columnItem.name"
                    v-slot:[getTableColumnSlotName(columnItem.db)]="props"
                >
                    <q-td key="columnItem.name" :props="props">
                        <div v-if="isTableColumnGroupTypeText(columnItem.db)">
                            <div v-if="props.row[columnItem.name].length > 50">
                                {{
                                    props.row[columnItem.name].substr(0, 50)
                                }}...
                                <q-btn
                                    flat
                                    color="warning"
                                    size="xs"
                                    icon="open_in_new"
                                    @click="
                                        openDialogForTextData(
                                            columnItem.db,
                                            props.row[columnItem.name]
                                        )
                                    "
                                />
                            </div>
                            <div v-else>
                                {{ props.row[columnItem.name] }}
                            </div>
                        </div>
                        <div
                            v-else-if="
                                isTableColumnGroupTypeBlob(columnItem.db)
                            "
                        >
                            [BLOB]
                            <q-btn
                                flat
                                color="warning"
                                size="xs"
                                icon="open_in_new"
                                @click="
                                    openDialogForBlobData(
                                        columnItem.db,
                                        props.row[columnItem.name]
                                    )
                                "
                            />
                        </div>
                        <div
                            v-else-if="
                                isTableColumnGroupTypeNumeric(columnItem.db)
                            "
                        >
                            {{ props.row[columnItem.name] }}
                        </div>
                        <div
                            v-else-if="
                                isTableColumnGroupTypeInteger(columnItem.db)
                            "
                        >
                            {{ props.row[columnItem.name] }}
                        </div>
                        <div
                            v-else-if="
                                isTableColumnGroupTypeReal(columnItem.db)
                            "
                        >
                            {{ props.row[columnItem.name] }}
                        </div>
                        <div v-else :props="props">
                            <div v-if="props.row[columnItem.name].length > 50">
                                {{
                                    props.row[columnItem.name].substr(0, 50)
                                }}...
                                <q-btn
                                    flat
                                    color="warning"
                                    size="xs"
                                    icon="open_in_new"
                                    @click="
                                        openDialogForTextData(
                                            columnItem.db,
                                            props.row[columnItem.name]
                                        )
                                    "
                                />
                            </div>
                            <div v-else>
                                {{ props.row[columnItem.name] }}
                            </div>
                        </div>
                    </q-td>
                </template>
            </q-table>
        </div>
    </div>
</template>

<style scoped lang="sass">
.sticky-virtscroll-table
  /* height or max-height is important */
  height: 83vh

  .q-table__top,
  .q-table__bottom,
  thead tr:first-child th /* bg color is important for th; just specify one */
    background-color: #fff

  thead tr th
    position: sticky
    z-index: 1
  /* this will be the loading indicator */
  thead tr:last-child th
    /* height of all previous header rows */
    top: 48px
  thead tr:first-child th
    top: 0

.q-item__label
    overflow: hidden
</style>
