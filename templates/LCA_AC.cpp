
    {// getlca
        bool flag =1;
        if (dep[u]<dep[v]) swap(u,v);
        int tmpu = u;
        for (int i=20;i>=0;i--){
            if (dep[f[u][i]]>=dep[v]){
                u=f[u][i];
            }
        }
        if (u==v) {lca = u;}
        else {
            int tmpu,tmpv;
            tmpu=u;tmpv=v;
            for (int i=20;i>=0;i--){
                if (f[tmpu][i]!=f[tmpv][i]) tmpu = f[tmpu][i],tmpv = f[tmpv][i];
            }
            lca = f[tmpu][0];
        }
        u=uu,v=vv;
    }
