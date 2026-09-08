package com.miqayel.callguard

import android.os.Bundle
import android.app.role.RoleManager
import android.content.Intent
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Button
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Switch
import androidx.compose.material3.Text
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            var blockingEnabled by remember {
                mutableStateOf(GuardPreferences.isBlockingUnavailableCallers(this@MainActivity))
            }

            MaterialTheme {
                Scaffold { padding ->
                    Column(
                        modifier = Modifier
                            .fillMaxSize()
                            .padding(padding)
                            .padding(24.dp),
                        verticalArrangement = Arrangement.spacedBy(16.dp)
                    ) {
                        Text("Miqayel Call Guard", style = MaterialTheme.typography.headlineSmall)
                        Text(
                            "Սովորական բջջային զանգերը չեն հասնի սարք, եթե SIM/eSIM կամ համար չկա։"
                        )
                        Text(
                            "Այս պաշտպանությունը մերժում է այն զանգերը, որոնց համարը հասանելի չէ։"
                        )
                        Button(onClick = ::requestCallScreeningRole) {
                            Text("Միացնել զանգերի ֆիլտրը")
                        }
                        Switch(
                            checked = blockingEnabled,
                            onCheckedChange = {
                                blockingEnabled = it
                                GuardPreferences.setBlockingUnavailableCallers(this@MainActivity, it)
                            }
                        )
                        Text(if (blockingEnabled) "Պաշտպանությունը միացված է" else "Պաշտպանությունը անջատված է")
                        Text(
                            "Wi‑Fi զանգերը (օրինակ՝ WhatsApp կամ Telegram) կարգավորվում են այդ հավելվածներում։"
                        )
                    }

                    private fun requestCallScreeningRole() {
                        val roleManager = getSystemService(RoleManager::class.java)
                        if (roleManager.isRoleAvailable(RoleManager.ROLE_CALL_SCREENING) &&
                            !roleManager.isRoleHeld(RoleManager.ROLE_CALL_SCREENING)
                        ) {
                            startActivity(
                                roleManager.createRequestRoleIntent(RoleManager.ROLE_CALL_SCREENING)
                            )
                        }
                    }
                }
            }
        }
    }
}
