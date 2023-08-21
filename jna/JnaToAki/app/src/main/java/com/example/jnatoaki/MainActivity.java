package com.example.jnatoaki;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

import com.example.jnatoaki.databinding.ActivityMainBinding;
import com.sun.jna.Callback;
import com.sun.jna.Memory;
import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import com.sun.jna.Callback;
import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private ActivityMainBinding binding;

//    public static String name = "abcd";
//    public static String name2 = "abcd";
//    public static int age = 21;
    public static double num = 100.00;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        String name = "abcd";
        Memory strMemory = new Memory(name.length() + 1);
        strMemory.setString(0, name);
        change.C.changeName(strMemory);
        name = strMemory.getString(0);
        System.out.println("name1:" + name);

        String name2 = "abcd";
        name2 = change.C.changeName2();
        System.out.println("name2:" + name2);

        int age = 21;
        Memory ageMemory = new Memory(4);
        ageMemory.setInt(0, age);
        change.C.changeNum(ageMemory);
        age = ageMemory.getInt(0);
        System.out.println("after changed: " + age);

        num = change.C.changeDouble();
        System.out.println("num:" + num);

        System.out.println("final number: " + change.C.add1(5, 5));

        int area = MyRectangle.myRectangle.calculateArea(3, 4);
        int perimeter = MyRectangle.myRectangle.calculatePerimeter(3, 4);
        System.out.println("Area: " + area);
        System.out.println("Perimeter: " + perimeter);

        AddNumber.MyLib.INSTANCE.addN(new AddNumber.MyLib.addNumber() {
            public int add(int num1, int num2) {
                return num1 + num2;
            }
        });
        AddNumber.MyLib.INSTANCE.show(new AddNumber.MyLib.addNumber1() {
            public String show(String s, int num) {
                return num + s;
            }
        });

        structExample.MyStructure.ByReference s = new structExample.MyStructure.ByReference();
        s.a = 2;
        s.b = 3;
        int result = structExample.MyLibrary.lib.add(s);
        System.out.println("Result: " + result);
    }
}

interface change extends Library {
    change C = (change) Native.load("jnatoaki", change.class);
    void changeName(Pointer str);
    String changeName2();
    void changeNum(Pointer num);
    double changeDouble();
    int add1(int a, int b);
}

interface MyRectangle extends Library{
    MyRectangle myRectangle = (MyRectangle) Native.load("jnatoaki", MyRectangle.class);
    int calculateArea(int length, int width);
    int calculatePerimeter(int length, int width);
}

class structExample {
    public static class MyStructure extends Structure {
        public static class ByReference extends MyStructure implements Structure.ByReference {}
        public int a;
        public int b;
        @Override
        protected List<String> getFieldOrder() {
            return Arrays.asList("a", "b");
        }
    }
    public interface MyLibrary extends Library {
        MyLibrary lib = (MyLibrary) Native.load("jnatoaki", MyLibrary.class);
        int add(MyStructure.ByReference s);
    }
}

class AddNumber {
    public interface MyLib extends Library {
        MyLib INSTANCE = (MyLib) Native.load("jnatoaki", MyLib.class);

        interface addNumber extends Callback {
            int add(int num1, int num2);

        }
        interface addNumber1 extends Callback {
            String show(String s, int num);
        }
        void addN(addNumber callback);
        void show(addNumber1 callback);
    }
}
