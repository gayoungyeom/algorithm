function solution(rows, columns, queries) {
    const rotate = (arr) => {
        let newArr = JSON.parse(JSON.stringify(arr));
        const n = arr.length;
        const m = arr[0].length;
        
        for(let i = 1; i < m; i++)
            newArr[0][i] = arr[0][i - 1];
        for(let i = 0; i < n - 1; i++)
            newArr[i][0] = arr[i + 1][0];
        for(let i = 0; i < m - 1; i++)
           newArr[n - 1][i] = arr[n - 1][i + 1];
        for(let i = 1; i < n; i++)
           newArr[i][m - 1] = arr[i - 1][m - 1];
        
        return newArr;
    }
    
    //배열 초기화
    let k = 1;
    let arr = Array.from(Array(rows), () => Array(columns).fill(0));
    for(let i = 0; i < rows; i++){
        for(let j = 0; j < columns; j++){
            arr[i][j] = i  * columns + j + 1;
        }
    }

    const result = [];
    for(const query of queries){
        const [x1, y1, x2, y2] = query;
        
        //회전할 부분
        const sub = [];
        for(let i = x1 - 1; i < x2; i++){
            const tmp = [];
            for(let j = y1 - 1; j < y2; j++){
                tmp.push(arr[i][j]);
            }
            sub.push(tmp);
        }

        const rotated = rotate(sub);
        
        //회전 결과 반영
        for(let i = 0; i < rotated.length; i++){
            for(let j = 0; j < rotated[i].length; j++){
                arr[i + x1 - 1][j + y1 - 1] = rotated[i][j];
            }
        }
        
        //회전한 숫자 중 최솟값 찾기
        let min = Infinity;
        const n = rotated.length;
        const m = rotated[0].length;
        for(let i = 0; i < n; i++){
            min = Math.min(min, rotated[i][0]);
            min = Math.min(min, rotated[i][m - 1]);
        }
        for(let i = 0; i < m; i++){
            min = Math.min(min, rotated[0][i]);
            min = Math.min(min, rotated[n - 1][i]);
        }    
        
        result.push(min);
    }
    
    return result;
}
