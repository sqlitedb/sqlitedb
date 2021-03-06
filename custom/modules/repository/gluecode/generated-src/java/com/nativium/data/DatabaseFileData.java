// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from proj.djinni

package com.nativium.data;

public final class DatabaseFileData {


    /*package*/ final String mName;

    /*package*/ final long mFileSize;

    /*package*/ final String mFilePath;

    public DatabaseFileData(
            String name,
            long fileSize,
            String filePath) {
        this.mName = name;
        this.mFileSize = fileSize;
        this.mFilePath = filePath;
    }

    public String getName() {
        return mName;
    }

    public long getFileSize() {
        return mFileSize;
    }

    public String getFilePath() {
        return mFilePath;
    }

    @Override
    public String toString() {
        return "DatabaseFileData{" +
                "mName=" + mName +
                "," + "mFileSize=" + mFileSize +
                "," + "mFilePath=" + mFilePath +
        "}";
    }

}
