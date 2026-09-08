# Miqayel Call Guard

An Android starter app for defensive call filtering.

## Scope

- Android's normal cellular call service does not receive calls when a device has no
  SIM/eSIM or phone number.
- `CallScreeningService` rejects calls whose caller identity is unavailable (for
  example, private/hidden callers).
- Internet calls from apps such as WhatsApp or Telegram are outside Android's
  cellular call-screening API and must be restricted in those apps separately.

This app does not identify or locate callers. It only applies local, user-controlled
blocking rules.

After installing, open the app and grant it the Android call-screening role. The
operating system controls whether that role is available on a particular device.