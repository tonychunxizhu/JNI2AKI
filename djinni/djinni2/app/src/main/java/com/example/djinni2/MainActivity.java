package com.example.djinni2;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

import com.example.djinni2.databinding.ActivityMainBinding;

//import com.zhoumohan.djinni.databinding.ActivityMain2Binding;
import com.zhoumohan.djinni.gen.SexModeEnum;
import com.zhoumohan.djinni.gen.TestDjnniInterface;
import com.zhoumohan.djinni.gen.TestInfoStore;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'djinni2' library on application startup.
    static {
        System.loadLibrary("djinni2");
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


        com.zhoumohan.djinni.gen.TestDjnniInterface djnniInterface = com.zhoumohan.djinni.gen.TestDjnniInterface.newInstance();
        com.zhoumohan.djinni.gen.TestInfoStore infoStore = new com.zhoumohan.djinni.gen.TestInfoStore(1234,"djinni test ","djinni", SexModeEnum.SEX_MAN);
        String a = djnniInterface.show(infoStore);
        tv.setText(a);
    }

    /**
     * A native method that is implemented by the 'djinni2' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}

//
//public class MainActivity1 extends AppCompatActivity {
//    static {
//        System.loadLibrary("mytest");
//    }
//
//    ActivityMain2Binding binding;
//    @Override
//    protected void onCreate(Bundle savedInstanceState) {
//        super.onCreate(savedInstanceState);
//        binding = ActivityMain2Binding.inflate(getLayoutInflater());
//        setContentView(binding.getRoot());
//
//        binding.btn.setOnClickListener(view -> {
//            com.zhoumohan.djinni.gen.TestDjnniInterface djnniInterface = com.zhoumohan.djinni.gen.TestDjnniInterface.newInstance();
//            com.zhoumohan.djinni.gen.TestInfoStore infoStore = new com.zhoumohan.djinni.gen.TestInfoStore(1234,"测试测试","djinni", SexModeEnum.SEX_MAN);
//            String a = djnniInterface.show(infoStore);
//            binding.tv.setText(a);
//        });
//    }
//}