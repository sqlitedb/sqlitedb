import { defineStore } from "pinia";

export const useWasmModuleStore = defineStore({
    id: "wasm-module",
    state: () => ({
        loaded: false,
    }),
    getters: {
        isLoaded: (state) => state.loaded,
    },
    actions: {
        setLoaded(value) {
            this.loaded = value;
        },
    },
});
