package com.example.wavemaker;

import android.annotation.SuppressLint;
import android.os.Bundle;
import androidx.appcompat.app.AppCompatActivity;
import android.view.MotionEvent;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    TextView textView;

    static {
        System.loadLibrary("wavemaker");
    }

    private native int touchEvent(int action, int pos_y);

    private native void startEngine();

    private native void stopEngine();

    @SuppressLint("SetTextI18n")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        textView = findViewById(R.id.TextView);
        startEngine();
    }

    @SuppressLint("SetTextI18n")
    @Override
    public boolean onTouchEvent(MotionEvent event) {
        int pos_y = (int)event.getY();
        textView.setText(touchEvent(event.getAction(), pos_y) + " Hz");
        return super.onTouchEvent(event);
    }

    @Override
    public void onDestroy() {
        stopEngine();
        super.onDestroy();
    }
}