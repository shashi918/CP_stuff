//The Hashtag Generator
/*
The marketing team is spending way too much time typing in hashtags.
Let's help them with our own Hashtag Generator!

Here's the deal:

    It must start with a hashtag (#).
    All words must have their first letter capitalized.
    If the final result is longer than 140 chars it must return false.
    If the input or the result is an empty string it must return false.

Examples

" Hello there thanks for trying my Kata"  =>  "#HelloThereThanksForTryingMyKata"
"    Hello     World   "                  =>  "#HelloWorld"
""                                        =>  false

*/

function generateHashtag(str) {
    let temp = str.replace(' ', "");
  if (temp == 0) return false;
console.log(str)
  if(str.length <= 1)
    return false;
  str = str.split(" ");
  let ans = "#";
  for (let i = 0; i < str.length; i++) {
      str[i] = str[i].charAt(0).toUpperCase() + str[i].slice(1);
      ans += str[i];
  }
if(ans.length>140)
  return false;
  return ans;
}

console.log(generateHashtag("     "));