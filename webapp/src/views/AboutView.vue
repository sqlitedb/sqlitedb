<script setup>
import AboutDataVue from "../components/AboutData.vue";
</script>

<template>
    <div class="main-container">
        <div class="container q-pa-md q-mt-xl text-center">
            <img
                alt="SQLite Data Browser Logo"
                src="@/assets/logo.png"
                width="128"
                height="128"
            />

            <h3>SQLite Data Browser</h3>

            <AboutDataVue />

            <q-separator />

            <br />

            <p>
                This is an open-source software made by
                <a href="https://github.com/paulocoutinhox" target="_blank">
                    Paulo Coutinho </a
                >.
            </p>
            <p>
                You can see the source code here:
                <a href="https://github.com/sqlitedb/sqlitedb" target="_blank">
                    https://github.com/sqlitedb/sqlitedb
                </a>
            </p>
        </div>
    </div>
</template>

<style scoped>
/* ignore */
</style>
