<script setup>
import { ref } from "vue";
import AboutDataVue from "../components/AboutData.vue";
import MainContentVue from "../components/MainContent.vue";
import SideBarVue from "../components/SideBar.vue";
import { useRepositoryStore } from "../stores/repository";

const repository = useRepositoryStore();
const splitterModel = ref(20);
</script>

<template>
    <keep-alive>
        <div v-if="repository.isLoaded">
            <q-splitter v-model="splitterModel" style="height: 100vh">
                <!-- SIDE BAR -->
                <template v-slot:before>
                    <SideBarVue />
                </template>

                <!-- MAIN CONTENT -->
                <template v-slot:after>
                    <MainContentVue />
                </template>
            </q-splitter>
        </div>
        <div v-else>
            <div class="container q-pa-md q-mt-xl text-center">
                <img
                    alt="SQLite Data Browser Logo"
                    src="@/assets/logo.png"
                    width="128"
                    height="128"
                />

                <AboutDataVue />
            </div>
        </div>
    </keep-alive>
</template>
