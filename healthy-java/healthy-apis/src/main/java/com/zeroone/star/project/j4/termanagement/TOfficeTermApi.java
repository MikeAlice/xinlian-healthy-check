package com.zeroone.star.project.j4.termanagement;

import com.zeroone.star.project.j4.query.SwitchTermQuery;
import com.zeroone.star.project.vo.JsonVO;


public interface TOfficeTermApi {

    JsonVO<Boolean> switchTerm(SwitchTermQuery query) throws Exception;



}
