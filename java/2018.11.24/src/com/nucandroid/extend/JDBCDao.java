package com.nucandroid.extend;

public class JDBCDao {
    public interface SaveListener{
        void onSucceed(String json);

        void onFail();
    }
}
