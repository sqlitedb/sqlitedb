import { defineStore } from "pinia";
import CDatabaseItem from "../classes/database-item";

export const useRepositoryStore = defineStore({
    id: "repository",
    state: () => ({
        loaded: false,
        info: {},
        databaseItems: [CDatabaseItem],
        currentDatabaseItem: null,
    }),
    getters: {
        isLoaded: (state) => state.loaded,
    },
    actions: {
        reset() {
            this.loaded = false;
            this.info = {};
            this.currentDatabaseItem = null;
            this.databaseItems = [];
        },
        setLoaded(value) {
            this.loaded = value;
        },
        setInfo(value) {
            this.info = value;
        },
        setCurrentDatabaseItem(value) {
            this.currentDatabaseItem = value;
        },
        addDatabaseItem(itemType, itemName) {
            let found = false;

            for (var x = 0; x < this.databaseItems.length; x++) {
                let databaseItem = this.databaseItems[x];

                if (
                    databaseItem.itemType == itemType &&
                    databaseItem.itemName == itemName
                ) {
                    found = true;
                }
            }

            if (!found) {
                let dbItem = new CDatabaseItem(itemType, itemName);
                dbItem.load();

                this.databaseItems.push(dbItem);
            }
        },
        removeDatabaseItem(itemType, itemName) {
            let foundIndex = -1;
            let isCurrent = false;

            for (var x = 0; x < this.databaseItems.length; x++) {
                let databaseItem = this.databaseItems[x];

                if (
                    databaseItem.itemType == itemType &&
                    databaseItem.itemName == itemName
                ) {
                    foundIndex = x;

                    if (this.currentDatabaseItem != null) {
                        if (
                            this.currentDatabaseItem.itemType == itemType &&
                            this.currentDatabaseItem.itemName == itemName
                        ) {
                            isCurrent = true;
                        }
                    }
                }
            }

            if (isCurrent) {
                this.setCurrentDatabaseItem = null;
            }

            if (foundIndex >= 0) {
                this.databaseItems.splice(foundIndex, 1);
            }
        },
        setDatabaseItem(itemType, itemName) {
            let foundIndex = -1;
            let isCurrent = false;

            for (var x = 0; x < this.databaseItems.length; x++) {
                let databaseItem = this.databaseItems[x];

                if (
                    databaseItem.itemType == itemType &&
                    databaseItem.itemName == itemName
                ) {
                    foundIndex = x;

                    if (this.currentDatabaseItem != null) {
                        if (
                            this.currentDatabaseItem.itemType == itemType &&
                            this.currentDatabaseItem.itemName == itemName
                        ) {
                            isCurrent = true;
                        }
                    }
                }
            }

            if (isCurrent) {
                return;
            }

            if (foundIndex >= 0) {
                this.setCurrentDatabaseItem(this.databaseItems[foundIndex]);
            } else {
                this.addDatabaseItem(itemType, itemName);
                this.setCurrentDatabaseItem(
                    this.databaseItems[this.databaseItems.length - 1]
                );
            }
        },
    },
});
