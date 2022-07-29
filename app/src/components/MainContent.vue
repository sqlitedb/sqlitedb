<script setup>
import { useRepositoryStore } from "../stores/repository";
import DatabaseItem from "./DatabaseItem.vue";
const repository = useRepositoryStore();
</script>

<template>
    <div v-if="repository.currentDatabaseItem">
        <DatabaseItem />
    </div>
    <div class="q-mt-lg" v-else>
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
</template>

<style scoped>
/* ignore */
</style>
