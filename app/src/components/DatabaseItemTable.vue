<script setup>
import { useRepositoryStore } from "../stores/repository";
const repository = useRepositoryStore();

function onRequest(props) {
    repository.currentDatabaseItem.load(props);
}
</script>

<template>
    <div>
        <div class="no-shadow">
            <q-item>
                <q-item-section side>
                    <q-avatar
                        icon="table_rows"
                        color="indigo"
                        text-color="white"
                        size="24px"
                    />
                </q-item-section>
                <q-item-section>
                    <q-item-label
                        >Table:
                        {{
                            repository.currentDatabaseItem.itemName
                        }}</q-item-label
                    >
                </q-item-section>
            </q-item>

            <q-table
                class="custom-table no-border-radius no-shadow"
                :rows="repository.currentDatabaseItem.rows"
                :columns="repository.currentDatabaseItem.columns"
                row-key="index"
                virtual-scroll
                separator="cell"
                v-model:pagination="repository.currentDatabaseItem.pagination"
                @request="onRequest"
            />
        </div>
    </div>
</template>

<style scoped>
/* ignore */
</style>
