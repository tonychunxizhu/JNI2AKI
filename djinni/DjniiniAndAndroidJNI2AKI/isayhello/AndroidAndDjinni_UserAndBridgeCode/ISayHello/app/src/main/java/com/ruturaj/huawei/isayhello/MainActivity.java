package com.ruturaj.huawei.isayhello;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

import com.ruturaj.huawei.isayhello.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'isayhello' library on application startup.
    static {
        System.loadLibrary("isayhello");
    }

    private ActivityMainBinding binding;

    public static native void androidJNISayHello(int i);

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        tv.setText(stringFromJNI());

        androidJNISayHello(1);

        ISayHello djnniInterface = ISayHello.newInstance();
        MyRecord infoStore = new MyRecord(1234, "djinni test \n", "djinni", Gender.Man);
        String a = djnniInterface.sayHello(infoStore);
        tv.setText(a);
    }

    /**
     * A native method that is implemented by the 'isayhello' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}