//Human Readable Format
/*
Write a function, which takes a non-negative integer (seconds) as input and returns the time in a human-readable format (HH:MM:SS)

    HH = hours, padded to 2 digits, range: 00 - 99
    MM = minutes, padded to 2 digits, range: 00 - 59
    SS = seconds, padded to 2 digits, range: 00 - 59

The maximum time never exceeds 359999 (99:59:59)

You can find some examples in the test fixtures.
*/
function humanReadable(time) {
  if (time == 0)
    return "00:00:00";
  let seconds = 0;
  let minutes = 0;
  let hours = 0;
  if (time >= 3600) {
    hours = parseInt(time / 3600);
    time = parseInt(time % 3600);
  }
  if (time >= 60) {
    minutes = parseInt(time / 60);
    time = parseInt(time % 60);
  }
  let ans = "";
  if (hours < 10) {
    ans += "0" + hours + ":";
  } else {
    ans += hours + ":";
  }
  if (minutes < 10) {
    ans += "0" + minutes + ":";
  } else {
    ans += minutes + ":";
  }
  if (time < 10) {
    ans += "0" + time;
  } else {
    ans += time;
  }
  return ans;
}

console.log(humanReadable(86399));
