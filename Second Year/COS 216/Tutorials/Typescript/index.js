var list = [4, 5, 6];
for (var i in list) {
    console.log(i); // "0", "1", "2"
}
for (var _i = 0, list_1 = list; _i < list_1.length; _i++) {
    var i = list_1[_i];
    console.log(i); // "4", "5", "6"
}
