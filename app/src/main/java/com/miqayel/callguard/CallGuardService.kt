package com.miqayel.callguard

import android.telecom.Call
import android.telecom.CallScreeningService

class CallGuardService : CallScreeningService() {
    override fun onScreenCall(callDetails: Call.Details) {
        val handle = callDetails.handle
        val hasUsableNumber = handle?.scheme == "tel" && !handle.schemeSpecificPart.isNullOrBlank()
        val shouldBlock = GuardPreferences.isBlockingUnavailableCallers(this) && !hasUsableNumber

        val response = CallResponse.Builder()
            .setDisallowCall(shouldBlock)
            .setRejectCall(shouldBlock)
            .setSkipCallLog(shouldBlock)
            .setSkipNotification(shouldBlock)
            .build()

        respondToCall(callDetails, response)
    }
}
