import './App.css';

// 1. 定義點擊事件函式 (講義第 53 頁)
const changeText = (event) => {
  console.log(event.target);
  // 文字點擊後加上 "被點了"
  event.target.innerText = event.target.innerText + "被點了";
};

function App() {
  // 2. 定義樣式參數 (講義第 48 頁)
  const styleArgument = {
    color: 'red',
    fontSize: '50px'
  };

  return (
    <div className="App">
      {/* 3. 綁定樣式與點擊功能 */}
      <h1 style={styleArgument} onClick={changeText}>
        hello CGU!!
      </h1>
    </div>
  );
}

export default App;
