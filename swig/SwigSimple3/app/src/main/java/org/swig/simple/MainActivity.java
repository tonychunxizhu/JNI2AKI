package org.swig.simple;

//import static org.swig.swigsimple.example.gcd;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.ScrollView;
import android.text.method.ScrollingMovementMethod;


public class MainActivity extends Activity
{
    TextView outputText = null;
    ScrollView scroller = null;
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        outputText = (TextView)findViewById(R.id.OutputText);
        outputText.setText("Press 'Run' to start...\n");
      //  Log.d("GCD", "onCreate: "+gcd(1,2));
        outputText.setMovementMethod(new ScrollingMovementMethod());
        scroller = (ScrollView)findViewById(R.id.Scroller);
    }
    public void onRunButtonClick(View view)
    {
        outputText.append("Started...\n");
        nativeCall();
        outputText.append("Finished!\n");
// Ensure scroll to end of text
        scroller.post(new Runnable() {
            public void run() {
                scroller.fullScroll(ScrollView.FOCUS_DOWN);
            }
        });
    }
    /** Calls into C/C++ code */
    /** Calls into C/C++ code */
    public void nativeCall()
    {
        // Call our gcd() function
        int x = 42;
        int y = 105;
        int g = example.gcd(x, y);
        outputText.append("The greatest common divisor of " + x + " and " + y + " is " + g + "\n");
// Manipulate the Foo global variable
// Output its current value
        double foo = example.getFoo();
        outputText.append("Foo = " + foo + "\n");
// Change its value
        example.setFoo(3.1415926);
// See if the change took effect
        outputText.append("Foo = " + example.getFoo() + "\n");
// Restore value
        example.setFoo(foo);

    }

    /** static constructor */
    static {
        System.loadLibrary("example");
    }
}
//package org.swig.simple;
//
//import androidx.appcompat.app.AppCompatActivity;
//
//import android.os.Bundle;
//import android.widget.TextView;
//
//import org.swig.simple.databinding.ActivityMainBinding;
//
//public class MainActivity extends AppCompatActivity {
//
//    // Used to load the 'simple' library on application startup.
//    static {
//        System.loadLibrary("simple");
//    }
//
//    private ActivityMainBinding binding;
//
//    @Override
//    protected void onCreate(Bundle savedInstanceState) {
//        super.onCreate(savedInstanceState);
//
//        binding = ActivityMainBinding.inflate(getLayoutInflater());
//        setContentView(binding.getRoot());
//
//        // Example of a call to a native method
//        TextView tv = binding.sampleText;
//        tv.setText(stringFromJNI());
//    }
//
//    /**
//     * A native method that is implemented by the 'simple' native library,
//     * which is packaged with this application.
//     */
//    public native String stringFromJNI();
//}