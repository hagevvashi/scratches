async function main(){
  await Promise.all([...Array(1000).keys()].map(async (v) => {
    console.log(v);
    await new Promise((resolve) => {
      setTimeout(() => {
        resolve();
      }, 3000)
    });
    console.log(`${v}...done`);
    return;
  }));
}

main().then(() => {
  console.log("all done");
});