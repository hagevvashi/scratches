async function main() {
  const appElement = document.getElementById("app");

  const date = new Date();
  const yyyymmdd = `${date.getFullYear()}${`0${date.getMonth()}`.slice(
    -2
  )}${`0${date.getDate()}`.slice(-2)}${`0${date.getHours()}`.slice(
    -2
  )}${`0${date.getMinutes()}`.slice(-2)}${`0${date.getSeconds()}`.slice(-2)}`;

  const url = process.env.URL;

  const response = await fetch(
    `${url}?${yyyymmdd}`,
    {
      method: "GET",
    }
  );
  const data = await response.json();

  appElement.innerHTML = `
    <h1>This is the ${data.firstName}</h1>
    <dl>
      <dt>id</dt>
      <dd>${data.id}</dd>
      <dt>first name</dt>
      <dd>${data.firstName}</dd>
      <dt>last name</dt>
      <dd>${data.lastName}</dd>
    </dl>
  `;
}

main();
