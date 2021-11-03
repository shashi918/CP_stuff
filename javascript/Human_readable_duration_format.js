//Human readable duration format
/*
Your task in order to complete this Kata is to write a function which formats a duration, given as a number of seconds, in a human-friendly way.

The function must accept a non-negative integer. If it is zero, it just returns "now". Otherwise, the duration is expressed as a combination of years, days, hours, minutes and seconds.

It is much easier to understand with an example:

formatDuration(62)    // returns "1 minute and 2 seconds"
formatDuration(3662)  // returns "1 hour, 1 minute and 2 seconds"

For the purpose of this Kata, a year is 365 days and a day is 24 hours.

Note that spaces are important.
Detailed rules

The resulting expression is made of components like 4 seconds, 1 year, etc. In general, a positive integer and one of the valid units of time, separated by a space. The unit of time is used in plural if the integer is greater than 1.

The components are separated by a comma and a space (", "). Except the last component, which is separated by " and ", just like it would be written in English.

A more significant units of time will occur before than a least significant one. Therefore, 1 second and 1 year is not correct, but 1 year and 1 second is.

Different components have different unit of times. So there is not repeated units like in 5 seconds and 1 second.

A component will not appear at all if its value happens to be zero. Hence, 1 minute and 0 seconds is not valid, but it should be just 1 minute.

A unit of time must be used "as much as possible". It means that the function should not return 61 seconds, but 1 minute and 1 second instead. Formally, the duration specified by of a component must not be greater than any valid more significant unit of time.
*/
function formatDuration(seconds) {
    let i = 0;
    let arr = [0, 0, 0, 0, 0];
    let time_arr = ["year", "day", "hour", "minute", "second"];
    let time_arr_count = [31536000, 86400, 3600, 60, 1];
    let counter = 0;

    while (seconds) {
        if (seconds >= time_arr_count[i]) {
                counter++;
            arr[i] = Math.floor(seconds / time_arr_count[i]);
            if (arr[i] > 1) {
                time_arr[i] = time_arr[i] + "s";
            }
            seconds = Math.floor(seconds % time_arr_count[i]);
            i++;
        } else {
            i++;
        }
    }
    let index = counter;
    let ans = 0;
    for (let i = 0; i < 5; i++) {
        if (arr[i] != 0) {
            ans = ans + arr[i] + " " + time_arr[i];
            if (counter>=2&&index-1==1) {
                ans = ans + " and "
                index--;
            } else {
                ans = ans + ", ";
                index--;
            }
        }
    }
    ans = ans.substring(0, ans.length - 2);

    return ans;
}

console.log(formatDuration(1));
console.log(formatDuration(62));
console.log(formatDuration(120));
console.log(formatDuration(3600));
console.log(formatDuration(3662));
console.log(formatDuration(8988000)); //104 days, 40 minutes;