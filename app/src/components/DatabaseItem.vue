<script setup>
import { useRepositoryStore } from "../stores/repository";
import DatabaseItemTable from "./DatabaseItemTable.vue";
import DatabaseItemView from "./DatabaseItemView.vue";
const repository = useRepositoryStore();
</script>

<template>
    <div v-if="repository.currentDatabaseItem.itemType == 'table'">
        <DatabaseItemTable />
    </div>
    <div v-else-if="repository.currentDatabaseItem.itemType == 'view'">
        <DatabaseItemView />
    </div>
    <div v-else>
        <div class="container q-pa-md q-mt-xl text-center">
            <img
                alt="SQLite Data Browser Logo"
                src="@/assets/logo.png"
                width="128"
                height="128"
            />

            <p class="q-mt-sm">
                Unknow database type ({{
                    repository.currentDatabaseItem.itemType
                }})
            </p>
        </div>
    </div>
</template>

<style scoped>
/* ignore */
</style>
