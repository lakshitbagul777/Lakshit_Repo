
var elements = document.getElementsByName("cssProperty");

let div = document.getElementById("modify");

function set()
{
    for(let i=0; i<elements.length; i++)
    {
        let property = elements[i].getAttribute('id');
        let value = elements[i].value;

        modify.style[property] = value;
    }
}