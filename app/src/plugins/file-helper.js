import { useRepositoryStore } from "../stores/repository";

export default {
    install: (app) => {
        app.provide("FileHelper", {
            open(onSuccess, onError) {
                var input = document.createElement("input");
                input.type = "file";

                input.onchange = async (e) => {
                    try {
                        // module
                        const WM = app.config.globalProperties.$WM;

                        // file reference
                        var file = e.target.files[0];

                        // read file bytes
                        let fileByteArray = await this.fileToByteArray(file);

                        if (fileByteArray.length <= 0) {
                            onError({
                                message: "The database file is invalid",
                            });
                            return;
                        }

                        let data = new Uint8Array(fileByteArray);

                        // store the file on virtual file system
                        let filename = "sqlitedb.db";
                        let stream = WM.FS.open(filename, "w+");
                        WM.FS.write(stream, data, 0, data.length, 0);
                        WM.FS.close(stream);

                        // open
                        WM.Repository.shared().open(filename);

                        // store info
                        const repository = useRepositoryStore();
                        repository.setInfo(WM.Repository.shared().getInfo());
                        repository.setLoaded(true);

                        onSuccess();
                    } catch (error) {
                        onError({ message: error });
                        return;
                    }
                };

                input.click();
            },

            fileToByteArray(file) {
                return new Promise((resolve, reject) => {
                    try {
                        let reader = new FileReader();
                        let fileByteArray = [];

                        reader.readAsArrayBuffer(file);
                        reader.onloadend = (evt) => {
                            if (evt.target.readyState == FileReader.DONE) {
                                let arrayBuffer = evt.target.result;
                                let array = new Uint8Array(arrayBuffer);

                                for (var x = 0; x < array.length; x++) {
                                    fileByteArray.push(array[x]);
                                }
                            }
                            resolve(fileByteArray);
                        };
                    } catch (e) {
                        reject(e);
                    }
                });
            },
        });
    },
};
