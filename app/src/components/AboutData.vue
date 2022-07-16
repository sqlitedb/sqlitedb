<script setup>
import { useWasmModuleStore } from "../stores/wasm-module";

const wm = useWasmModuleStore();
</script>

<template>
    <div class="q-mt-lg" v-if="wm.isLoaded">
        <p>
            SQLite Version:
            {{ $WM.Repository.shared().getSqliteVersion() }}
        </p>
        <p>
            Wasm Module Version:
            {{ $WM.ApplicationCore.shared().getVersion() }}
        </p>
    </div>
    <div class="q-mt-lg" v-else>
        <p>Loading Wasm module...</p>
    </div>
</template>

<style scoped>
/* ignore */
</style>
