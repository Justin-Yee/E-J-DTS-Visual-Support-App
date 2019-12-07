package com.example.proj;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class changePassword extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_change_password);

        configurechangePasswordButton();
    }

    private void configurechangePasswordButton(){
        Button changePasswordButton = (Button) findViewById(R.id.changePassword);
        changePasswordButton.setOnClickListener(new View.OnClickListener(){

            @Override
            public void onClick(View view){
                startActivity(new Intent(changePassword.this, mainmenu.class));
            }
        });
    }
}
