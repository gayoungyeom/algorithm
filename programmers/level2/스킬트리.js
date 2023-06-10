function solution(skill, skill_trees) {
    let count = 0;

    for(const skill_tree of skill_trees){
        const skillTree = [...skill_tree].filter(tree => skill.includes(tree));
        
        let flag = true;
        for(let i = 0; i < Math.min(skill.length, skillTree.length); i++){
            if(skillTree[i] !== skill[i]){
                flag = false;
                break;
            }
        }
        if(flag) count++;
    }
    
    return count;
}
