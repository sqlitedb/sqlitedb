<script setup>
import { ref } from "vue";
import { useRepositoryStore } from "../stores/repository";
import { useWasmModuleStore } from "../stores/wasm-module";
import StringHelper from "../classes/string-helper";

const wm = useWasmModuleStore();
const repository = useRepositoryStore();

const menuTablesExpanded = ref(true);
const menuViewsExpanded = ref(true);
const menuInformationsExpanded = ref(true);

const colorForTables = "indigo";
const colorForViews = "indigo";
const colorForInformations = "teal";
</script>

<template>
    <q-list class="list scroll sidebar-list">
        <!-- TABLES -->
        <q-expansion-item v-model="menuTablesExpanded">
            <template v-slot:header>
                <q-item-section side>
                    <q-avatar
                        icon="table_rows"
                        :color="colorForTables"
                        text-color="white"
                        size="24px"
                    />
                </q-item-section>

                <q-item-section>Tables</q-item-section>
            </template>

            <q-item
                clickable
                v-ripple
                dense
                v-for="item in repository.info.tables"
                :key="item"
                @click="repository.setDatabaseItem('table', item.name)"
            >
                <q-item-section side>
                    <q-icon
                        :color="colorForTables"
                        text-color="white"
                        size="24px"
                        name="keyboard_arrow_right"
                    />
                </q-item-section>
                <q-item-section>{{ item.name }}</q-item-section>
            </q-item>
        </q-expansion-item>

        <q-separator />

        <!-- VIEWS -->
        <q-expansion-item v-model="menuViewsExpanded">
            <template v-slot:header>
                <q-item-section side>
                    <q-avatar
                        icon="flash_on"
                        :color="colorForViews"
                        text-color="white"
                        size="24px"
                    />
                </q-item-section>

                <q-item-section>Views</q-item-section>
            </template>

            <q-item
                clickable
                v-ripple
                dense
                v-for="item in repository.info.views"
                :key="item"
                @click="repository.setDatabaseItem('view', item.name)"
            >
                <q-item-section side>
                    <q-icon
                        :color="colorForViews"
                        text-color="white"
                        size="24px"
                        name="keyboard_arrow_right"
                    />
                </q-item-section>
                <q-item-section>{{ item.name }}</q-item-section>
            </q-item>
        </q-expansion-item>

        <q-separator />

        <!-- INFO -->
        <q-expansion-item v-model="menuInformationsExpanded">
            <template v-slot:header>
                <q-item-section side>
                    <q-avatar
                        icon="help_center"
                        :color="colorForInformations"
                        text-color="white"
                        size="24px"
                    />
                </q-item-section>

                <q-item-section>Informations</q-item-section>
            </template>

            <!-- DATABASE NAME -->
            <q-item dense>
                <q-item-section side>
                    <q-icon
                        :color="colorForInformations"
                        text-color="white"
                        size="24px"
                        name="keyboard_arrow_right"
                    />
                </q-item-section>
                <q-item-section>
                    Name:
                    {{ repository.info.fileData.name }}
                </q-item-section>
            </q-item>

            <!-- FILE PATH -->
            <q-item dense>
                <q-item-section side>
                    <q-icon
                        :color="colorForInformations"
                        text-color="white"
                        size="24px"
                        name="keyboard_arrow_right"
                    />
                </q-item-section>
                <q-item-section>
                    File path:
                    {{ repository.info.fileData.filePath }}
                </q-item-section>
            </q-item>

            <!-- FILE SIZE -->
            <q-item dense>
                <q-item-section side>
                    <q-icon
                        :color="colorForInformations"
                        text-color="white"
                        size="24px"
                        name="keyboard_arrow_right"
                    />
                </q-item-section>
                <q-item-section>
                    File size:
                    {{
                        StringHelper.humanFileSize(
                            Number(repository.info.fileData.fileSize)
                        )
                    }}
                </q-item-section>
            </q-item>

            <!-- SQLITE VERSION -->
            <q-item dense>
                <q-item-section side>
                    <q-icon
                        :color="colorForInformations"
                        text-color="white"
                        size="24px"
                        name="keyboard_arrow_right"
                    />
                </q-item-section>
                <q-item-section>
                    SQLite Version:
                    {{ wm.module.Repository.shared().getSqliteVersion() }}
                </q-item-section>
            </q-item>

            <!-- WASM MODULE VERSION -->
            <q-item dense>
                <q-item-section side>
                    <q-icon
                        :color="colorForInformations"
                        text-color="white"
                        size="24px"
                        name="keyboard_arrow_right"
                    />
                </q-item-section>
                <q-item-section>
                    Wasm Module Version:
                    {{ wm.module.ApplicationCore.shared().getVersion() }}
                </q-item-section>
            </q-item>
        </q-expansion-item>
    </q-list>
</template>

<style scoped>
.sidebar-list {
    height: 94hv;
}
</style>
