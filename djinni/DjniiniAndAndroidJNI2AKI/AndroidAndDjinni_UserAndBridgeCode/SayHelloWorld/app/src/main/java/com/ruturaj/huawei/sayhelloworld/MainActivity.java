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
            Log.d("RRR", String.valueOf(listener));
        }

        @Override
        public void removeSayHelloListener(boolean listener) {
            Log.d("RRR", String.valueOf(listener));
        }

        @Override
        public void sayHello(String from, String to) {
            Log.d("RRR", from + " " + to);
        }

        @Override
        public void destroy() {

        }
    };

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
    }

    /**
     * A native method that is implemented by the 'sayhelloworld' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}