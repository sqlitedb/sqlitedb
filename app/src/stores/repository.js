import { defineStore } from "pinia";

export const useRepositoryStore = defineStore({
    id: "repository",
    state: () => ({
        loaded: false,
        info: {},
    }),
    getters: {
        isLoaded: (state) => state.loaded,
    },
    actions: {
        setLoaded(value) {
            this.loaded = value;
        },
        setInfo(value) {
            this.info = value;
        },
    },
});
