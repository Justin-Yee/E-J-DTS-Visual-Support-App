package com.example.proj;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class mainmenu extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_mainmenu);

        configureLogoutButton();
        configureExistingReportsButton();
        configureCreateReportsButton();
        configureContactButton();
    }

    private void configureLogoutButton() {
        Button logoutButton = findViewById(R.id.logout);
        logoutButton.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View view) {
                startActivity(new Intent(mainmenu.this, MainActivity.class));
            }
        });
    }

    private void configureExistingReportsButton() {
        Button existingReportsButton = findViewById(R.id.existingReport);
        existingReportsButton.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View view) {
                startActivity(new Intent(mainmenu.this, viewExitingReports.class));
            }
        });
    }

    private void configureCreateReportsButton() {
        Button createReportsButton = findViewById(R.id.createReport);
        createReportsButton.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View view) {
                startActivity(new Intent(mainmenu.this, CreateReport.class));
            }
        });
    }

    private void configureContactButton() {
        Button createReportsButton = findViewById(R.id.Contact);
        createReportsButton.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View view) {
                startActivity(new Intent(mainmenu.this, contactPage.class));
            }
        });
    }
}
