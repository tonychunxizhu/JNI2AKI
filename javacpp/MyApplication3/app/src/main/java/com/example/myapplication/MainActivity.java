package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.example.myapplication.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'myapplication' library on application startup.
    static {
        System.loadLibrary("myapplication");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        tv.setText(stringFromJNI());

        // Example calling a C++ object using JavaCPP
        NativeLibrary.NativeClass nc = new NativeLibrary.NativeClass();
        nc.set_property("Hello from JavaCPP");
        tv.setText(nc.get_property().getString());
        Log.i("test-TAG",nc.get_property().getString());
        nc.set_value("Hello, I am JavaCpp");
        Log.i("test-TAG",nc.get_value().getString());

        nc.set_year(2024);
        Log.i("test-TAG","I am from "+Integer.toString(nc.get_year()));

        Log.i("test-TAG", "call add: "+Integer.toString(nc.add(1000,1023)));



        NativeLibrary.Foo f = new NativeLibrary.Foo(10) {
            public int bar(int a,int b) {
                return Integer.valueOf(Integer.toString(a)+Integer.toString(b));
            }
        };

        Log.i("test-TAG","call = "+Integer.toString(f.bar(41,42)));
        Log.i("test-TAG","callback  = "+ Integer.toString(NativeLibrary.callback(f,41,42)));

    }

    /**
     * A native method that is implemented by the 'myapplication' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}