<script setup>
import { useRepositoryStore } from "../stores/repository";
import DatabaseItem from "./DatabaseItem.vue";
const repository = useRepositoryStore();

function onRequest(databaseItem, props) {
    databaseItem.load(props);
}
</script>

<template>
    <div v-if="repository.databaseItems">
        <q-tabs
            v-model="repository.currentTab"
            dense
            class="text-grey"
            active-color="primary"
            indicator-color="primary"
            align="justify"
            narrow-indicator
        >
            <q-tab
                v-for="databaseItem in repository.databaseItems"
                :key="databaseItem.id"
                :name="databaseItem.itemName"
                :label="databaseItem.itemName"
            />
        </q-tabs>
        <q-separator />
        <q-tab-panels v-model="repository.currentTab" animated>
            <q-tab-panel
                v-for="databaseItem in repository.databaseItems"
                :key="databaseItem.id"
                :name="databaseItem.itemName"
                class="q-pa-none"
            >
                <DatabaseItem
                    :databaseItem="databaseItem"
                    @onRequest="(props) => onRequest(databaseItem, props)"
                />
            </q-tab-panel>
        </q-tab-panels>
    </div>
    <div v-else>
        <div class="main-container">
            <div class="container q-pa-md q-mt-xl text-center">
                <img
                    alt="SQLite Data Browser Logo"
                    src="@/assets/logo.png"
                    width="128"
                    height="128"
                />

                <p class="q-mt-sm">No database item selected</p>
            </div>
        </div>
    </div>
</template>

<style scoped>
/* ignore */
</style>
