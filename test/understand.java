
package com.example.userinputj;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;


public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView tv = (TextView)findViewById(R.id.view01);
        tv.setText("JK test");
    }
/*
    public static void main(){
        TextView textView = (TextView) view.findViewById(R.id.textView);
        textView.setText("Jk test");
    }
*/
}
