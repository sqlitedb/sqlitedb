import { defineStore } from "pinia";

/**
 * @typedef {Object} WasmModule
 * @property {import("../../../nativium/modules/app-core/gluecode/generated-src/ts/app-core").ApplicationCore_statics} ApplicationCore
 * @property {import("../../../nativium/modules/repository/gluecode/generated-src/ts/repository").Repository_statics} Repository
 */

export const useWasmModuleStore = defineStore({
    id: "wasm-module",
    state: () => ({
        loaded: false,

        /** @type {WasmModule} */
        module: null,
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
