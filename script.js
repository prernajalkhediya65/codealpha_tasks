let input = document.getElementById('inputBox');
let buttons = document.querySelectorAll('button');

let string = "";
let arr = Array.from(buttons);
arr.forEach(button => {
    button.addEventListener('click', (e) => {
        handleinput(e.target.innerText);
    });
});
document.addEventListener('keydown', (e) => {
    input.focus();


    if (e.key === "Enter") {
        handleinput("=");
    }
    else if (e.key === "Backspace") {
        handleinput("DEL");

    }
    else if (e.key === "Escape") {
        handleinput("AC");
    }
    else if ("0123456789+-*/.".includes(e.key)) {
        handleinput(e.key);
    }
});
function handleinput(value) {
    if (value === '=') {
        try {
            string = eval(string);
            input.value = string;
        } catch {
            string = "error";
            input.value = string;

        }
    }
    else if (value === 'AC') {
        string = "";
        input.value = string;

    }
    else if (value === 'DEL') {
        string = string.slice(0, -1);
        input.value = string;
    }
    else {
        string += value;
        input.value = string;
    }

}







