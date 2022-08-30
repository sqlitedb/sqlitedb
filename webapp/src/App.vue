<script setup>
import { useQuasar } from "quasar";
import { inject, onMounted } from "vue";
import { RouterView, useRouter } from "vue-router";
import UrlHelper from "./classes/url-helper";
import { useWasmModuleStore } from "./stores/wasm-module";

const wm = useWasmModuleStore();
const router = useRouter();
const FileHelper = inject("FileHelper");
const Application = inject("Application");
const q = useQuasar();

function showLoading() {
    q.loading.show({
        message: "Loading...",
    });
}

function hideLoading() {
    q.loading.hide();
}

function openNewFile() {
    Application.reset();
    router.push("/");

    FileHelper.openLocalFile(
        () => {
            hideLoading();

            q.dialog({
                title: "Open",
                message: "Database opened with success",
            });

            router.push("/");
        },
        () => {
            showLoading();
        },
        (e) => {
            hideLoading();

            q.dialog({
                title: "Open",
                message: e.message.toString(),
            });
        }
    );
}

function newInstance() {
    router.push("/");
    Application.reset();
}

function checkForRemoteFile() {
    let file = UrlHelper.getUrlParam("f");

    if (file) {
        FileHelper.openFromRemoteFile(
            file,
            () => {
                hideLoading();

                q.dialog({
                    title: "Open",
                    message: "Database opened with success",
                });

                router.push("/");
            },
            () => {
                showLoading();
            },
            (e) => {
                hideLoading();

                q.dialog({
                    title: "Open",
                    message: e.message.toString(),
                });
            }
        );
    }
}

onMounted(() => {
    showLoading();
});

wm.$subscribe((mutation, state) => {
    if (state.loaded) {
        hideLoading();
        checkForRemoteFile();
    }
});
</script>

<template>
    <div>
        <q-layout view="lHh lpr lFf" class="shadow-2">
            <q-header elevated>
                <q-bar>
                    <q-icon name="laptop_chromebook" />
                    <div class="cursor-pointer" @click="$router.push('/')">
                        SQLite Data Browser
                    </div>
                    <q-space />

                    <div v-if="wm.isLoaded">
                        <q-badge>{{
                            wm.module.ApplicationCore.shared().getVersion()
                        }}</q-badge>
                    </div>
                </q-bar>

                <div class="q-pa-sm q-pl-md row items-center">
                    <div class="cursor-pointer non-selectable">
                        File
                        <q-menu>
                            <q-list dense style="min-width: 100px">
                                <q-item clickable v-close-popup>
                                    <q-item-section @click="newInstance()"
                                        >New</q-item-section
                                    >
                                </q-item>

                                <q-separator />

                                <q-item clickable v-close-popup>
                                    <q-item-section @click="openNewFile()"
                                        >Open...</q-item-section
                                    >
                                </q-item>
                            </q-list>
                        </q-menu>
                    </div>

                    <div class="q-ml-md cursor-pointer non-selectable">
                        More
                        <q-menu auto-close>
                            <q-list dense style="min-width: 100px">
                                <q-item clickable>
                                    <q-item-section
                                        @click="$router.push('/about')"
                                        >About</q-item-section
                                    >
                                </q-item>
                            </q-list>
                        </q-menu>
                    </div>
                </div>
            </q-header>

            <q-page-container style="padding-top: 0; height: 100vh">
                <router-view v-slot="{ Component }">
                    <transition>
                        <keep-alive :include="['MainView']">
                            <component :is="Component"></component>
                        </keep-alive>
                    </transition>
                </router-view>
            </q-page-container>
        </q-layout>
    </div>
</template>

<style>
@import "@/assets/base.css";
</style>
