window.addEventListener("error", (e) => {
  console.log("error catch");
  console.log("error message");
  console.log(e.message);
});

window.addEventListener("unhandledrejection", (error, promise) => {
  console.log(error.reason);
});

async function sleep(ms) {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve();
    }, ms);
  });
}

async function prepare() {
  return new Promise((resolve) => {
    if (document.readyState !== "loading") {
      return resolve();
    }
    window.addEventListener("DOMContentLoaded", () => {
      resolve();
    });
  });
}

async function main() {
  await sleep(3000);
  await prepare();
  const app = document.getElementById("app");
  console.log(app);
  const wrapper = document.createElement("div");
  wrapper.innerHTML = `
    <h1>Hello</h1>
    <div>
      foofoofoo
    </div>
  `;
  app.append(wrapper);
  throw new Error("eeeeeeeee");
}

main();
