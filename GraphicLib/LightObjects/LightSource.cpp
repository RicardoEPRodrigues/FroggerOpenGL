/*
 * LightSource.cpp
 *
 *  Created on: Oct 22, 2014
 *      Author: ricardo
 */

#include "LightSource.h"

using namespace std;

LightSource::LightSource() {

    _cut_off = 0.0f;
    _exponent = 1.0f;
    _state = true;
    _isSpot = false;

    _constAtt = 0;
    _lineAtt = 0;
    _quadAtt = 0;
}

LightSource::~LightSource() {
}

void LightSource::draw(Engine* engine, int index) {
    GLint loc;

    float lightPos[4] = {this->_position.getX(), this->_position.getY(),
                         this->_position.getZ(), this->_position.getW()};
    float res[4], res1[4];
    engine->matrixModule->multMatrixPoint(VIEW, lightPos,
                                          res); //lightPos definido em World Coord so is converted to eye space
    glUniform4fv(engine->lPos_uniformId[index], 1, res);

    float spotDir[4] = {this->_direction.getX(), this->_direction.getY(),
                        this->_direction.getZ(), 0.0f};
    engine->matrixModule->multMatrixPoint(VIEW, spotDir, res1);
    glUniform4fv(engine->sDir_uniformId, 1, res1);

    string source = "lit[" + to_string(index) + "]";

    char argument[40];

    strcpy(argument, (source + ".ambient").c_str());
    loc = glGetUniformLocation(engine->shader.getProgramIndex(), (const GLchar*) &argument);
    float amb[4] = {this->_ambient.getX(), this->_ambient.getY(), this->_ambient.getZ(), this->_ambient.getW()};
    glUniform4fv(loc, 1, amb);

    strcpy(argument, (source + ".diffuse").c_str());
    loc = glGetUniformLocation(engine->shader.getProgramIndex(), (const GLchar*) &argument);
    float dif[4] = {this->_diffuse.getX(), this->_diffuse.getY(), this->_diffuse.getZ(), this->_diffuse.getW()};
    glUniform4fv(loc, 1, dif);

    strcpy(argument, (source + ".specular").c_str());
    loc = glGetUniformLocation(engine->shader.getProgramIndex(), (const GLchar*) &argument);
    float spc[4] = {this->_specular.getX(), this->_specular.getY(), this->_specular.getZ(), this->_specular.getW()};
    glUniform4fv(loc, 1, spc);

    strcpy(argument, (source + ".isSpot").c_str());
    loc = glGetUniformLocation(engine->shader.getProgramIndex(), (const GLchar*) &argument);
    if (this->_isSpot)
        glUniform1f(loc, 1.0f);
    else
        glUniform1f(loc, 0.0f);

    strcpy(argument, (source + ".isLocal").c_str());
    loc = glGetUniformLocation(engine->shader.getProgramIndex(), (const GLchar*) &argument);
    if (this->_position.getW() == 1.0f)
        glUniform1f(loc, 1.0f);
    else
        glUniform1f(loc, 0.0f);

    strcpy(argument, (source + ".position").c_str());
    loc = glGetUniformLocation(engine->shader.getProgramIndex(), (const GLchar*) &argument);
    float pos[4] = {this->_position.getX(), this->_position.getY(), this->_position.getZ(), this->_position.getW()};
    engine->matrixModule->multMatrixPoint(VIEW, pos, res);
    glUniform4fv(loc, 1, res1);

    //strcpy(argument, source); std::strcat(argument, "lightDirection");
    //loc = glGetUniformLocation(engine->shader.getProgramIndex(), (const GLchar*)&argument);
    //float dir[3] = { res[0], res[1], res[2]/*, 1.0f*/ };
    //engine->matrixModule->multMatrixPoint(VIEW, dir, res1);
    //float dir1[3] = { res1[0], res1[1], res1[2] };
    //glUniform3fv(loc, 1, dir1);

    strcpy(argument, (source + ".spotDirection").c_str());
    loc = glGetUniformLocation(engine->shader.getProgramIndex(), (const GLchar*) &argument);
    //float dir[3] = { res1[0], res1[1], res1[2]/*, 1.0f*/ };
    //engine->matrixModule->multMatrixPoint(VIEW, dir, res1);
    float dir1[3] = {res1[0], res1[1], res1[2]};
    glUniform3fv(loc, 1, dir1);

    strcpy(argument, (source + ".spotCosCutoff").c_str());
    loc = glGetUniformLocation(engine->shader.getProgramIndex(), (const GLchar*) &argument);
    glUniform1f(loc, this->_cut_off);

    //strcpy(argument, source); std::strcat(argument, ".exponent");
    //loc = glGetUniformLocation(engine->shader.getProgramIndex(), (const GLchar*)&argument);
    //glUniform1f(loc, this->_exponent);

    //strcpy(argument, source); std::strcat(argument, ".constAtt");
    //loc = glGetUniformLocation(engine->shader.getProgramIndex(), (const GLchar*)&argument);
    //glUniform1f(loc, this->_constAtt);

    //strcpy(argument, source); std::strcat(argument, ".lineAtt");
    //loc = glGetUniformLocation(engine->shader.getProgramIndex(), (const GLchar*)&argument);
    //glUniform1f(loc, this->_lineAtt);

    //strcpy(argument, source); std::strcat(argument, ".quadAtt");
    //loc = glGetUniformLocation(engine->shader.getProgramIndex(), (const GLchar*)&argument);
    //glUniform1f(loc, this->_quadAtt);

    strcpy(argument, (source + ".isEnabled").c_str());
    loc = glGetUniformLocation(engine->shader.getProgramIndex(), (const GLchar*) &argument);
    if (this->_state)
        glUniform1f(loc, 1.0f);
    else
        glUniform1f(loc, 0.0f);

    /**/
}
