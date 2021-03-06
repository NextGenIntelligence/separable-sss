/**
 * Copyright (C) 2012 Jorge Jimenez (jorge@iryoku.com). All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *    1. Redistributions of source code must retain the above copyright notice,
 *       this list of conditions and the following disclaimer.
 *
 *    2. Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS
 * IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are 
 * those of the authors and should not be interpreted as representing official
 * policies, either expressed or implied, of the copyright holders.
 */


#ifndef SKYDOME_H
#define SKYDOME_H

#include <string>
#include "SDKmisc.h"
#include "SDKmesh.h"
#include "RenderTarget.h"

class SkyDome {
    public:
        SkyDome(ID3D10Device *device, const std::wstring &dir, float intensity=1.0f);
        ~SkyDome();
        
        void render(const D3DXMATRIX &view, const D3DXMATRIX &projection, float scale);
        void setDirectory(const std::wstring &dir);
    
        void setIntensity(float intensity) { this->intensity = intensity; }
        float getIntensity() const { return intensity; }

        void setAngle(const D3DXVECTOR2 &angle) { this->angle = angle; }
        D3DXVECTOR2 getAngle() const { return angle; }

    private:
        void createMesh(const std::wstring &dir);
        static void CALLBACK createTextureFromFile(ID3D10Device* device, 
                                                   char *filename, 
                                                   ID3D10ShaderResourceView **shaderResourceView,
                                                   void *context, 
                                                   bool srgb);

        ID3D10Device *device;
        ID3D10Effect *effect;
        CDXUTSDKMesh mesh;
        float intensity;
        D3DXVECTOR2 angle;
};

#endif
