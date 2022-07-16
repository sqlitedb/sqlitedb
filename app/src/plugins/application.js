import { useRepositoryStore } from "../stores/repository";

export default {
    install: (app) => {
        app.provide("Application", {
            reset() {
                const repository = useRepositoryStore();
                repository.setLoaded(false);
                repository.setInfo({});

                app.config.globalProperties.$WM.Repository.shared().close();
            },
        });
    },
};
