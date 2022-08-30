import { defineStore } from "pinia";
import CDatabaseItem from "../classes/database-item";

export const useRepositoryStore = defineStore({
    id: "repository",
    state: () => ({
        loaded: false,
        info: {},
        databaseItems: [],
        currentTab: null,
    }),
    getters: {
        isLoaded: (state) => state.loaded,
    },
    actions: {
        reset() {
            this.loaded = false;
            this.info = {};

            /** @type {CDatabaseItem[]} */
            this.databaseItems = [];
        },
        setLoaded(value) {
            this.loaded = value;
        },
        setInfo(value) {
            this.info = value;
        },
        updateCurrentTab(databaseItem) {
            if (databaseItem == null) {
                this.currentTab = "";
            } else {
                this.currentTab = databaseItem.itemName;
            }
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

                    if (this.currentTab != null) {
                        if (this.currentTab == itemName) {
                            isCurrent = true;
                        }
                    }

                    break;
                }
            }

            if (isCurrent) {
                this.updateCurrentTab(null);
            }

            if (foundIndex >= 0) {
                this.databaseItems.splice(foundIndex, 1);
            }

            if (this.currentTab == "") {
                if (this.databaseItems.length > 0) {
                    let databaseItem =
                        this.databaseItems[this.databaseItems.length - 1];

                    this.updateCurrentTab(databaseItem);
                }
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

                    if (this.currentTab != null) {
                        if (this.currentTab == itemName) {
                            isCurrent = true;
                        }
                    }
                }
            }

            if (isCurrent) {
                return;
            }

            if (foundIndex >= 0) {
                this.updateCurrentTab(this.databaseItems[foundIndex]);
            } else {
                this.addDatabaseItem(itemType, itemName);
                this.updateCurrentTab(
                    this.databaseItems[this.databaseItems.length - 1]
                );
            }
        },
    },
});
