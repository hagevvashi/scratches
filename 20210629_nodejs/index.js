async function main(){
  await Promise.all([...Array(1000).keys()].map(async (v) => {
    console.log(v);
    return new Promise((resolve) => {
      setTimeout(() => {
        console.log(`${v}...done`);
        resolve();
      }, 3000)
    })
  }));
}

main().then(() => {
  console.log("all done");
});