function varargout = adimat_diff_eig2(varargin)
[varargout{2}, varargout{4}]=eig(varargin{2}); 
tmp1 = inv(varargout{2}); 
tmp2 = adimat_mtimes_dv(adimat_mtimes_vd(tmp1, varargin{1}), varargout{2});
tmp3 = d_eig_F(diag(varargout{4}));
varargout{3} = adimat_diff_diag(adimat_diff_diag(tmp2, varargin{2}), diag(varargin{2})); 
varargout{1} = adimat_mtimes_vd(varargout{2}, adimat_times_dv(tmp2, tmp3));
end
% automatically generated from $Id: derivatives-vdd.xml 3983 2013-12-21 11:20:23Z willkomm $
