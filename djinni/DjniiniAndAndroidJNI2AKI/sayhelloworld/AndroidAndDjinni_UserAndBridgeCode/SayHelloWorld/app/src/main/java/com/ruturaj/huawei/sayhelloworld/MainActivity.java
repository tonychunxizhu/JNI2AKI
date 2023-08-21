package com.ruturaj.huawei.sayhelloworld;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.ruturaj.huawei.sayhelloworld.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'sayhelloworld' library on application startup.
    static {
        System.loadLibrary("sayhelloworld");
    }

    private ActivityMainBinding binding;

    public native static int sayHello(int i);

    ISayHello iSayHello = new ISayHello() {
        @Override
        public void addSayHelloListener(long listener) {
            Log.e("RRR", String.valueOf(listener));
        }

        @Override
        public void removeSayHelloListener(boolean listener) {
            Log.e("RRR", String.valueOf(listener));
        }

        @Override
        public void sayHello(String from, String to) {
            Log.e("RRR", from + " " + to);
        }

        @Override
        public String getHelloWorld() {
            Log.e("RRR", "getHelloWorld");
            return null;
        }

        @Override
        public void destroy() {
            Log.e("RRR", "Released");
        }
    };

//    TestISayHello.CppProxy cppProxy = new TestISayHello.CppProxy(1L);

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        tv.setText(stringFromJNI());

        sayHello(1);

        iSayHello.addSayHelloListener(1000000000000000000L);
        iSayHello.removeSayHelloListener(true);
        iSayHello.sayHello("my", "world");
        iSayHello.getHelloWorld();
//        iSayHello.destroy();

//        cppProxy.addSayHelloListener(2000000000000000000L);
//        cppProxy.removeSayHelloListener(false);
//        cppProxy.sayHello("foo", "bar");
//        cppProxy.destroy();

        ISayHello iSayHello1 = ISayHello.newInstance();
        tv.setText(iSayHello1.getHelloWorld());
        Log.e("RRR NewInstance", String.valueOf(iSayHello1));
//        if(iSayHello1 == null) {
//            Log.e("RRR", "newInstance returned null!");
//            return;
//        }
//        iSayHello1.addSayHelloListener(3000000000000000000L);
//        iSayHello1.removeSayHelloListener(true);
//        iSayHello1.sayHello("john", "smith");
//        iSayHello1.destroy();
    }

    /**
     * A native method that is implemented by the 'sayhelloworld' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}