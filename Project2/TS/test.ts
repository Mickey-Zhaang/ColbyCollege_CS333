// console.log("Hello World");

interface LoginEvent {
  kind: "login"; // discriminant
  username: string;
  attempts: number;
}

interface ErrorEvent {
  kind: "error";
  errorCode: number;
  errorMessage: string;
}

type AppEvents = LoginEvent | ErrorEvent;

// processes different types of events (like a dispathcer)
function processEvent(event: AppEvents) {
  switch (event.kind) {
    case "error":
      console.log(
        `Error as occured\nError Code: ${event.errorCode}\nError Message: ${event.errorMessage}`,
      );
      break;
    case "login":
      console.log(`Welcome ${event.username}`);
      break;
  }
}

// enforcing a type of LoginEvent
const event1: LoginEvent = {
  kind: "login",
  username: "Mikey",
  attempts: 0,
};

// process our custom event
processEvent(event1);
