<script setup>
import AboutDataVue from "../components/AboutData.vue";
</script>

<template>
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

        <p>This is an open-source software made by Paulo Coutinho.</p>
        <p>
            You can see the source code here:
            <a href="https://github.com/sqlitedb/sqlitedb" target="_blank">
                https://github.com/sqlitedb/sqlitedb
            </a>
        </p>

        <q-separator />

        <br />

        <p>This site is powered by Netlify.</p>

        <a href="https://www.netlify.com">
            <img
                src="https://www.netlify.com/v3/img/components/netlify-color-bg.svg"
                alt="Deploys by Netlify"
            />
        </a>

        <br />
    </div>
</template>
