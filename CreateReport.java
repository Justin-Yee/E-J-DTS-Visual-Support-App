package com.example.proj;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class CreateReport extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_create_report);

        configuresubmitButton();
    }

    private void configuresubmitButton(){
        Button submitButton = (Button) findViewById(R.id.submit);
        submitButton.setOnClickListener(new View.OnClickListener(){

            @Override
            public void onClick(View view){
                startActivity(new Intent(CreateReport.this, mainmenu.class));
            }
        });
    }
}
