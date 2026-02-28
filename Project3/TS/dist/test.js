"use strict";
// console.log("Hello World");
// processes different types of events (like a dispathcer)
function processEvent(event) {
    switch (event.kind) {
        case "error":
            console.log(`Error as occured\nError Code: ${event.errorCode}\nError Message: ${event.errorMessage}`);
            break;
        case "login":
            console.log(`Welcome ${event.username}`);
            break;
    }
}
// enforcing a type of LoginEvent
const event1 = {
    kind: "login",
    username: "Mikey",
    attempts: 0,
};
// process our custom event
processEvent(event1);
