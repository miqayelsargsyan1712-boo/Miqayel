package com.miqayel.callguard

import android.content.Context

object GuardPreferences {
    private const val FILE_NAME = "call_guard"
    private const val BLOCK_UNAVAILABLE_CALLERS = "block_unavailable_callers"

    fun isBlockingUnavailableCallers(context: Context): Boolean =
        context.getSharedPreferences(FILE_NAME, Context.MODE_PRIVATE)
            .getBoolean(BLOCK_UNAVAILABLE_CALLERS, true)

    fun setBlockingUnavailableCallers(context: Context, enabled: Boolean) {
        context.getSharedPreferences(FILE_NAME, Context.MODE_PRIVATE)
            .edit()
            .putBoolean(BLOCK_UNAVAILABLE_CALLERS, enabled)
            .apply()
    }
}
